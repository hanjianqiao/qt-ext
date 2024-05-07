#ifndef HWIDGET_GLOBAL_H
#define HWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HWIDGET_LIBRARY)
#define HWIDGET_EXPORT Q_DECL_EXPORT
#else
#define HWIDGET_EXPORT Q_DECL_IMPORT
#endif

#endif // HWIDGET_GLOBAL_H
