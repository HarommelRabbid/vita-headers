/**
 * \usergroup{SceClipboard}
 * \usage{psp2/clipboard.h,SceClipboard_stub,SCE_SYSMODULE_CLIPBOARD}
 */

#ifndef _PSP2_CLIPBOARD_H_
#define _PSP2_CLIPBOARD_H_

#include <psp2/types.h>
#include <psp2/libime.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Maximum length of clipboard input/output */
#define SCE_CLIPBOARD_MAX_STRING_LENGTH           8189

#define SCE_CLIPBOARD_ERROR_INTERNAL              0x80104600
#define SCE_CLIPBOARD_ERROR_NULL_POINTER          0x80104601
#define SCE_CLIPBOARD_ERROR_TEXT_TOO_LONG         0x80104602
#define SCE_CLIPBOARD_ERROR_UNSUPPORTED_CHARACTER 0x80104603

/**
 * Set clipboard text
 *
 * @param[out] newContents New text to be set for the clipboard
 * @param[in]  length      Length of text
 */
SceInt32 sceClipboardSetText(const SceWChar16* newContents, SceUInt length);

/**
 * Get clipboard text
 *
 * @param[out] buffer    New text to be set for the clipboard
 * @param[in]  maxlength Maximum length of returning text, use ::SCE_CLIPBOARD_MAX_STRING_LENGTH
 * @param[out] pLength    Length of returning text buffer.
 */
SceInt32 sceClipboardGetText(SceWChar16* buffer, SceUInt maxLength, SceUInt* pLength);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_CLIPBOARD_H_ */