#ifndef HCRYPTO_H
#define HCRYPTO_H

#include <QString>
#include <string>

namespace letiao {
class HCrypto
{
public:
    static QByteArray CBC_AESEncrypt(const QByteArray &plainData, const QByteArray &password, bool *ok = nullptr);
    static QByteArray CBC_AESDecrypt(const QByteArray &base64Data, const QByteArray &password, bool *ok = nullptr);
    static QByteArray RSA_Encrypt(const QByteArray &byteArray);
    static bool RSAVerifySignature(const QByteArray &signature, const QByteArray &data);
};
}

#endif // HCRYPTO_H
