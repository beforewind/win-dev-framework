/* 
 * 本软件为免费、开源软件。
 * 本软件的版权(包括源码及二进制发布版本)归一切公众所有。
 * 您可以自由使用、传播本软件。
 * 您也可以以任何形式、任何目的使用本软件(包括源码及二进制发布版本)，而不受任何版权限制。
 * =====================
 * 作者: 孙明保
 * 邮箱: sunmingbao@126.com
 */


#ifndef __GLOBAL_SYMBOLS_H_
#define __GLOBAL_SYMBOLS_H_

#include <windows.h>
#include <stdint.h>
#include "defs.h"



extern HINSTANCE g_hInstance;
extern int init_over;

int register_frame();
void set_frame_title(TCHAR *file_name);

BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT message,WPARAM wParam, LPARAM lParam);

extern HWND    hwnd_frame;
extern HWND hwndTip;
extern int  doc_modified;
void save_doc_file(TCHAR *file_name);
void load_doc_file(TCHAR *file_name);

#ifdef _USE_SPLITTER_FRAME
#define  WM_SPLITTER_X     (WM_USER + 3)
#define  WM_SPLITTER_Y     (WM_USER + 4)

extern TCHAR szLeftWinClassName[];
extern HWND  hwnd_left;
extern TCHAR szRightWinClassName[];
extern HWND    hwnd_right;
extern TCHAR szBottomWinClassName[];
extern HWND    hwnd_bottom;
#define    SPLT_WIDTH    (6)
extern TCHAR szSpltWeClassName[];
extern TCHAR szSpltNsClassName[];
void WriteInfo(TCHAR * szFormat, ...);
void PrintText(TCHAR * szFormat, ...);
void print_mem(void *start_addr, uint32_t length);
#ifdef _DEBUG
#define    DBG_PRINT(fmt, args...) \
    do \
    { \
        WriteInfo("DBG:%s(%d)-%s:\n"fmt"\n", __FILE__,__LINE__,__FUNCTION__,##args); \
    } while (0)
#else
#define    DBG_PRINT(fmt, args...) do { ; } while (0)
#endif
#endif

extern HWND    hwnd_toolbar;
extern int     toolbar_height;

extern HWND    hwnd_statusbar;
extern int     statusbar_height;


int CreateToolbar();
int CreateStatusBar();
void update_statusbar();
int create_windows(int iCmdShow);

void resize_window(HWND hwnd);

#endif

