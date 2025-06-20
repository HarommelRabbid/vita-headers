/**
 * \usergroup{SceScreenShot}
 * \usage{psp2/screenshot.h,SceScreenShot_stub,SCE_SYSMODULE_SCREEN_SHOT}
 */


#ifndef _PSP2_SCREENSHOT_H_
#define _PSP2_SCREENSHOT_H_

#include <vitasdk/build_utils.h>
#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SceScreenshotErrorCode {
	SCE_SCREENSHOT_ERROR_INVALID_ARGUMENT       = 0x80102F01,
	SCE_SCREENSHOT_ERROR_NO_MEMORY              = 0x80102F02,
	SCE_SCREENSHOT_ERROR_FILE_NOT_FOUND         = 0x80102F03,
	SCE_SCREENSHOT_ERROR_NOT_SUPPORTED_FORMAT   = 0x80102F04,
	SCE_SCREENSHOT_ERROR_MEDIA_FULL             = 0x80102F05,
	SCE_SCREENSHOT_ERROR_INTERNAL               = 0x80102F06
} SceScreenshotErrorCode;

//! Max size of path strings (includes device name and NULL terminator)
#define SCE_SCREENSHOT_MAX_FS_PATH		(1024)

//! Max length of photo title
#define SCE_SCREENSHOT_MAX_PHOTO_TITLE_LEN	(64)

//! Max size of photo title (includes NULL terminator)
#define SCE_SCREENSHOT_MAX_PHOTO_TITLE_SIZE (SCE_SCREENSHOT_MAX_PHOTO_TITLE_LEN * 4)

//! Max length of game title
#define SCE_SCREENSHOT_MAX_GAME_TITLE_LEN	(64)

//! Max size of game title (includes NUL terminator)
#define SCE_SCREENSHOT_MAX_GAME_TITLE_SIZE	(SCE_SCREENSHOT_MAX_GAME_TITLE_LEN * 4)

//! Max length of comment (description)
#define SCE_SCREENSHOT_MAX_GAME_COMMENT_LEN	(128)

//! Max size of comment (description) (includes NUL terminator)
#define SCE_SCREENSHOT_MAX_GAME_COMMENT_SIZE	(SCE_SCREENSHOT_MAX_GAME_COMMENT_LEN * 4)

typedef struct SceScreenShotParam {
	const SceWChar32 *photoTitle;   //!< Photo title
	const SceWChar32 *gameTitle;    //!< Game title
	const SceWChar32 *gameComment;  //!< Game description
	void *reserved;                 //!< Reserved range (Must be NULL)
} SceScreenShotParam;
VITASDK_BUILD_ASSERT_EQ(0x10, SceScreenShotParam);

/* Mode for screenshot capture */
typedef enum SceScreenShotCaptureMode {
	SCE_SCREENSHOT_CAPTURE_MODE_NORMAL           = 0,
	SCE_SCREENSHOT_CAPTURE_MODE_FORCE_CAPTURE    = 1,
} SceScreenShotCaptureMode;

/* Screenshot capture file information */
typedef struct SceScreenShotCaptureFileInfo {
	SceChar8 path[SCE_SCREENSHOT_MAX_FS_PATH];    /* path of capture file */
} SceScreenShotCaptureFileInfo;

/* Disable screenshot notification */
SceInt32 sceScreenShotDisableNotification(void);

/* Enable screenshot notification */
SceInt32 sceScreenShotEnableNotification(void);

/* Callback function */
typedef SceBool (*SceScreenShotCaptureCancelFunc)(void*);

/* Capture screenshot */
SceInt32 sceScreenShotCapture(
	SceScreenShotCaptureMode mode,
	SceScreenShotCaptureFileInfo *captureFileInfo,
	SceScreenShotCaptureCancelFunc cancelFunc,
	void *userdata);

//! Set screenshot params
int sceScreenShotSetParam(const SceScreenShotParam *param);

//! Set overlay image
int sceScreenShotSetOverlayImage(const char *filepath, int offsetX, int offsetY);

//! Disable screenshot
int sceScreenShotDisable(void);

//! Enable screenshot
int sceScreenShotEnable(void);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_SCREENSHOT_H_ */

