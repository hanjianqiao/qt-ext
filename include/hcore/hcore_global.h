#ifndef HCORE_GLOBAL_H
#define HCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HCORE_LIBRARY)
#define HCORE_EXPORT Q_DECL_EXPORT
#else
#define HCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // HCORE_GLOBAL_H
