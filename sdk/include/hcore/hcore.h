#ifndef HCORE_H
#define HCORE_H

#include "hcore_global.h"

class HCORE_EXPORT HCore
{
public:
    HCore();
};


class HCORE_EXPORT HCrypto
{
public:
    static QByteArray CBC_AESEncrypt(const QByteArray &plainData, const QByteArray &password, bool *ok = nullptr);
    static QByteArray CBC_AESDecrypt(const QByteArray &base64Data, const QByteArray &password, bool *ok = nullptr);
    static QByteArray RSA_Encrypt(const QByteArray &byteArray);
    static bool RSAVerifySignature(const QByteArray &signature, const QByteArray &data);
};

#endif // HCORE_H
