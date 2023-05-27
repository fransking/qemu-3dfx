/*
 * QEMU MESA GL Pass-Through
 *
 *  Copyright (c) 2020
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library;
 * if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MESAGL_IMPL_H
#define MESAGL_IMPL_H

#include <stdint.h>
#include "extensions_defs.h"
#include "mglfuncs.h"
#include "mglvarry.h"
#include "mglmapbo.h"
#include "mglcntx.h"

int GLFEnumArgsCnt(const int);
void *GLFEnumFuncPtr(const int);
int ExtFuncIsValid(const char *);
int GLIsD3D12(void);
int wrMapOrderPoints(uint32_t);
int wrSizeTexture(const int, const int, const int);
int wrSizeMapBuffer(const int);
void wrCompileShaderStatus(const int);
void wrFillBufObj(uint32_t, void *, mapbufo_t *);
void wrFlushBufObj(uint32_t, mapbufo_t *);
void wrContextSRGB(int);
void fgFontGenList(int, int, uint32_t);
const char *getGLFuncStr(int);
void doMesaFunc(int, uint32_t *, uintptr_t *, uintptr_t *);
void GLBufOAccelCfg(int);
void GLRenderScaler(int);
void GLContextMSAA(int);
void GLDispTimerCfg(int);
void GLExtUncapped(void);
int GetGLExtYear(void);
int GetGLExtLength(void);
int GetVertCacheMB(void);
int GetDispTimerMS(void);
int GetBufOAccelEN(void);
int GetContextMSAA(void);
int ContextUseSRGB(void);
int ContextVsyncOff(void);
int RenderScalerOff(void);
int SwapFpsLimit(int);
int GLShaderDump(void);
int GetFpsLimit(void);
int GLFifoTrace(void);
int GLFuncTrace(void);
void FiniMesaGL(void);
void ImplMesaGLReset(void);
int InitMesaGL(void);
void InitMesaGLExt(void);

#include <GL/glcorearb.h>
#define MESA_PFN(p,f) \
    p p_##f = (p)GLFEnumFuncPtr(FEnum_##f)
#define PFN_CALL(f) \
    p_##f
typedef void (APIENTRYP PFNGLBITMAPPROC) (GLsizei width,GLsizei height,GLfloat xorig,GLfloat yorig,GLfloat xmove,GLfloat ymove,const GLubyte *bitmap);
typedef void (APIENTRYP PFNGLENDLISTPROC) (void);
typedef void (APIENTRYP PFNGLNEWLISTPROC) (GLuint list,GLenum mode);
typedef void (APIENTRYP PFNGLGETMAPIVPROC) (GLenum target,GLenum query,GLint *v);

void MesaBlitFree(void);
void MesaBlitScale(void);
void MesaRenderScaler(const uint32_t, void *);

#endif //MESAGL_IMPL_H
