#ifndef HSTEGANOGRAPHY_H
#define HSTEGANOGRAPHY_H

#include <QByteArray>
#include <QImage>
#include "hwidget_global.h"

class HWIDGET_EXPORT HSteganography
{
public:
    enum MixLevel {
        Low,
        Medium,
        High,
    };

    // 64 bytes
    struct Header {
        std::uint8_t  sig[4];       // File Signature (HIDE)
        std::uint16_t version;      // Format Version
        std::uint8_t  level;        // Encoding level
        std::uint8_t  flags;        // Flags
        std::uint32_t offset;       // Offset to data
        std::uint32_t size;         // Size of data
        std::uint32_t hash;         // CRC32 hash of data
        std::uint8_t  name[32];     // File name, unused space filled with zeros
        std::uint8_t  reserved[12]; // Must be filled with zeros
    };
    static_assert(sizeof(Header) == 64);

    HSteganography();
};

class HWIDGET_EXPORT HImageSteganography
{
public:
    HImageSteganography();
    HImageSteganography(const QString &fileName);
    HImageSteganography(const QImage &image);
    void setImage(const QImage &image);
    QImage image() const;

    int encrypt(const QByteArray &name, const QByteArray &data, const QString &password);
    QPair<QByteArray, QByteArray> decrypt(const QString &password) const;

    qsizetype maxBytesCanWrite() const;

private:
    qsizetype writeData(const QByteArray &data, qsizetype offset);
    QByteArray readData(qsizetype byteSize, qsizetype offset) const;

private:
    QImage m_image;
};


#endif // HSTEGANOGRAPHY_H
