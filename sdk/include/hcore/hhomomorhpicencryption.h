#ifndef HHOMOMORHPICENCRYPTION_H
#define HHOMOMORHPICENCRYPTION_H

#include <gmp/gmp.h>
#include <mpfr/mpfr.h>
#include "hcore_global.h"

H_BEGIN_NAMESPACE

namespace HHomomorhpicEncryption{
namespace paillier{

class HCORE_EXPORT EncryptedNumber;
class HCORE_EXPORT EncodedNumber;

void lFunction(mpz_ptr out, mpz_srcptr x, mpz_srcptr p);

struct HCORE_EXPORT PublicKey{
public:
    static void getRandomLtN(mpz_t out, mpz_srcptr n);

    PublicKey(const PublicKey &other);
    PublicKey(mpz_srcptr n, mpz_srcptr g);
    ~PublicKey();

    PublicKey &operator=(const PublicKey &other) = delete;
    PublicKey &operator=(PublicKey &&other) = delete;

    mpz_srcptr n() const;
    mpz_srcptr g() const;
    mpz_srcptr nSquare() const;
    mpz_srcptr maxInt() const;

    int rawEncrypt(mpz_t out, mpz_srcptr plainValue, int r) const;
    EncryptedNumber encryptEncoded(const EncodedNumber &encoded, int r) const;

    // 加密函数
    EncryptedNumber encrypt(const EncodedNumber &encoded, int r = 0);
    EncryptedNumber encrypt(long plain, double precision = 0, int r = 0);
    EncryptedNumber encrypt(double plain, double precision = 0, int r = 0);

private:
    PublicKey();
    void initMembers();

private:
    mpz_t m_n;
    mpz_t m_g;
    mpz_t m_nSquare;
    mpz_t m_maxInt;

    friend class PrivateKey;
};

class HCORE_EXPORT PrivateKey{
public:
    static PrivateKey create(unsigned int nBits);
    PrivateKey(const PrivateKey &other);
    PrivateKey(mpz_srcptr p, mpz_srcptr q);
    PrivateKey(const char *pStr, const char *qStr, int base = 10);
    ~PrivateKey();

    PrivateKey &operator=(const PrivateKey &other) = delete;
    PrivateKey &operator=(PrivateKey &&other) = delete;

    mpz_srcptr p() const;
    mpz_srcptr q() const;
    mpz_srcptr n() const;
    mpz_srcptr nSquare() const;

    PublicKey getPublicKey() const;
    const PublicKey *publicKey() const;

    int rawDecrypt(mpz_t out, mpz_srcptr cipherValue) const;
    EncodedNumber decryptEncoded(const EncryptedNumber &encrypted) const;

    // 解密函数
    void decrypt(mpf_t out, const EncryptedNumber &encrypted) const;

private:
    void initMembers();
    void setPQ(mpz_srcptr p, mpz_srcptr q);
    void hFunction(mpz_ptr out, mpz_srcptr x, mpz_srcptr square);

private:
    mpz_t m_p;
    mpz_t m_q;
    mpz_t m_n;
    mpz_t m_g;
    mpz_t m_pSquare;
    mpz_t m_qSquare;
    mpz_t m_nSquare;
    mpz_t m_pInverse;
    mpz_t m_hp;
    mpz_t m_hq;
    mpz_t m_maxInt;

    PublicKey m_publicKey;
};


/*
    Return an encoding of an int or float.

    This encoding is carefully chosen so that it supports the same
    operations as the Paillier cryptosystem.

    If *scalar* is a float, first approximate it as an int, `int_rep`:

        scalar = int_rep * (:attr:`BASE` ** :attr:`exponent`),

    for some (typically negative) integer exponent, which can be
    tuned using *precision* and *max_exponent*. Specifically,
    :attr:`exponent` is chosen to be equal to or less than
    *max_exponent*, and such that the number *precision* is not
    rounded to zero.

    Having found an integer representation for the float (or having
    been given an int `scalar`), we then represent this integer as
    a non-negative integer < :attr:`~PaillierPublicKey.n`.

    Paillier homomorphic arithemetic works modulo
    :attr:`~PaillierPublicKey.n`. We take the convention that a
    number x < n/3 is positive, and that a number x > 2n/3 is
    negative. The range n/3 < x < 2n/3 allows for overflow
    detection.

    Args:
      public_key (PaillierPublicKey): public key for which to encode
        (this is necessary because :attr:`~PaillierPublicKey.n`
        varies).
      scalar: an int or float to be encrypted.
        If int, it must satisfy abs(*value*) <
        :attr:`~PaillierPublicKey.n`/3.
        If float, it must satisfy abs(*value* / *precision*) <<
        :attr:`~PaillierPublicKey.n`/3
        (i.e. if a float is near the limit then detectable
        overflow may still occur)
      precision (float): Choose exponent (i.e. fix the precision) so
        that this number is distinguishable from zero. If `scalar`
        is a float, then this is set so that minimal precision is
        lost. Lower precision leads to smaller encodings, which
        might yield faster computation.
      max_exponent (int): Ensure that the exponent of the returned
        `EncryptedNumber` is at most this.

    Returns:
      EncodedNumber: Encoded form of *scalar*, ready for encryption
      against *public_key*.
*/
class HCORE_EXPORT EncodedNumber
{
public:
    static EncodedNumber encode(const PublicKey *publicKey, mpz_srcptr scalar, double precision = 0, long maxExponent = 0);
    static EncodedNumber encode(const PublicKey *publicKey, mpf_srcptr scalar, double precision = 0, long maxExponent = 0);

    static int base();

    EncodedNumber(const PublicKey *publicKey, mpz_srcptr encoding, long exponent);
    EncodedNumber() = delete;
    EncodedNumber(const EncodedNumber &other);
    EncodedNumber &operator=(const EncodedNumber &other) = delete;
    EncodedNumber &operator=(EncodedNumber &&other) = delete;
    ~EncodedNumber();

    bool decode(mpf_t out);

    EncodedNumber decreaseExponentTo(long expo) const;

    mpz_srcptr encoding() const;
    long exponent() const;
    const PublicKey *publicKey() const;

private:
    static const int s_base = 16;
    static const int s_log2Base = 4; // math.log(BASE, 2)
    static const int s_floatMantissaBits = 53; // Python: sys.float_info.mant_dig

    const PublicKey *m_publicKey;
    mpz_t m_encoding;
    long m_exponent;
};

/*
    """Represents the Paillier encryption of a float or int.

    Typically, an `EncryptedNumber` is created by
    :meth:`PaillierPublicKey.encrypt`. You would only instantiate an
    `EncryptedNumber` manually if you are de-serializing a number
    someone else encrypted.


    Paillier encryption is only defined for non-negative integers less
    than :attr:`PaillierPublicKey.n`. :class:`EncodedNumber` provides
    an encoding scheme for floating point and signed integers that is
    compatible with the partially homomorphic properties of the Paillier
    cryptosystem:

    1. D(E(a) * E(b)) = a + b
    2. D(E(a)**b)     = a * b

    where `a` and `b` are ints or floats, `E` represents encoding then
    encryption, and `D` represents decryption then decoding.

    Args:
      public_key (PaillierPublicKey): the :class:`PaillierPublicKey`
        against which the number was encrypted.
      ciphertext (int): encrypted representation of the encoded number.
      exponent (int): used by :class:`EncodedNumber` to keep track of
        fixed precision. Usually negative.

    Attributes:
      public_key (PaillierPublicKey): the :class:`PaillierPublicKey`
        against which the number was encrypted.
      exponent (int): used by :class:`EncodedNumber` to keep track of
        fixed precision. Usually negative.

    Raises:
      TypeError: if *ciphertext* is not an int, or if *public_key* is
        not a :class:`PaillierPublicKey`.
    """
 */
class HCORE_EXPORT EncryptedNumber
{
public:
    EncryptedNumber() = delete;
    EncryptedNumber(const PublicKey *publicKey, mpz_srcptr cipherText, long expo);
    EncryptedNumber(const EncryptedNumber &other);
    EncryptedNumber &operator=(const EncryptedNumber &other) = delete;
    EncryptedNumber &operator=(EncryptedNumber &&other);
    ~EncryptedNumber();

    long exponent() const;
    EncryptedNumber decreaseExponentTo(long expo) const;

    void obfuscate();

    void ciphertext(mpz_t out, bool beSecure = true);
    void ciphertext(mpz_t out) const;

    // 运算
    EncryptedNumber operator+(const EncryptedNumber &other) const;
    // EncryptedNumber operator*(const long other) const;
    // EncryptedNumber operator*(const double other) const;
    EncryptedNumber operator*(mpz_srcptr other) const;
    EncryptedNumber operator*(mpf_srcptr other) const;
    // EncryptedNumber operator*(const EncodedNumber &other) const;

    void rawMul(mpz_t out, mpz_srcptr plainText) const;
    void _rawAdd(mpz_t out, mpz_srcptr a, mpz_srcptr b) const;

private:
    void initMembers();

private:
    const PublicKey *m_publicKey;
    mpz_t m_cipherText;
    long m_exponent;
    bool m_isObfuscated;
};

}
}

H_END_NAMESPACE
#endif // HHOMOMORHPICENCRYPTION_H
