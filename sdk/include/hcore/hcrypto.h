#ifndef HCRYPTO_H
#define HCRYPTO_H

#include "hcore_global.h"
#include <QString>

class HCryptoPrivate;

class HCORE_EXPORT HCrypto
{
public:
    enum AESMode{
        CBC,
    };

    enum AESFill{
        None,
        PKCS7,
    };

    enum AESKeySize{
        Length_128,
        Length_256,
    };

    HCrypto() = delete;

    static QByteArray CBC_AESEncrypt(const QByteArray &plainData, const QByteArray &password, bool *ok = nullptr);
    static QByteArray CBC_AESDecrypt(const QByteArray &base64Data, const QByteArray &password, bool *ok = nullptr);
    static QByteArray RSA_Encrypt(const QByteArray &byteArray);
    static bool RSAVerifySignature(const QByteArray &signature, const QByteArray &data);

    static QByteArray AESEncrypt(const QByteArray &plain, const QByteArray &key, const QByteArray &IV, AESMode mode = AESMode::CBC, AESFill fill = AESFill::PKCS7, AESKeySize keySize = AESKeySize::Length_128, bool *ok = nullptr);
    static QByteArray SM4Encrypt(const QByteArray &plain, const QByteArray &key, const QByteArray &IV, AESMode mode = AESMode::CBC, AESFill fill = AESFill::PKCS7, AESKeySize keySize = AESKeySize::Length_128, bool *ok = nullptr);

    static QPair<QByteArray, QByteArray> RasKeyGen(int bits);

private:
    Q_DISABLE_COPY(HCrypto)
    HCryptoPrivate *d;
};

#endif // HCRYPTO_H
