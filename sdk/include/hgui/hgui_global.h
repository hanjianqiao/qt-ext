#ifndef HGUI_GLOBAL_H
#define HGUI_GLOBAL_H

#include <QtCore/qglobal.h>
#include <h_global.h>

#if defined(HGUI_LIBRARY)
#define HGUI_EXPORT Q_DECL_EXPORT
#else
#define HGUI_EXPORT Q_DECL_IMPORT
#endif

#endif // HGUI_GLOBAL_H
