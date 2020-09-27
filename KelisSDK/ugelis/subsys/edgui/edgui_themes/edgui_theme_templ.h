/**
 * @file edgui_theme_templ.h
 *
 */

#ifndef EDGUI_THEME_TEMPL_H
#define EDGUI_THEME_TEMPL_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifdef EDGUI_CONF_INCLUDE_SIMPLE
#include "edgui_conf.h"
#else
#include "../edgui/edgui_conf.h"
#endif

#if EDGUI_USE_THEME_TEMPL

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the templ theme
 * @param hue [0..360] hue value from HSV color space to define the theme's base color
 * @param font pointer to a font (NULL to use the default)
 * @return pointer to the initialized theme
 */
edgui_theme_t * edgui_theme_templ_init(uint16_t hue, edgui_font_t * font);

/**
 * Get a pointer to the theme
 * @return pointer to the theme
 */
edgui_theme_t * edgui_theme_get_templ(void);

/**********************
 *      MACROS
 **********************/

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*EDGUI_THEME_TEMPL_H*/
