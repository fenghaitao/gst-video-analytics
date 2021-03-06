/*******************************************************************************
 * Copyright (C) <2018-2019> Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef _GST_GVA_META_CONVERT_H_
#define _GST_GVA_META_CONVERT_H_

#include <gst/base/gstbasetransform.h>
#include <gst/video/video.h>

G_BEGIN_DECLS

#define GST_TYPE_GVA_META_CONVERT (gst_gva_meta_convert_get_type())
#define GST_GVA_META_CONVERT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_GVA_META_CONVERT, GstGvaMetaConvert))
#define GST_GVA_META_CONVERT_CLASS(klass)                                                                              \
    (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_GVA_META_CONVERT, GstGvaMetaConvertClass))
#define GST_IS_GVA_META_CONVERT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_GVA_META_CONVERT))
#define GST_IS_GVA_META_CONVERT_CLASS(obj) (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_GVA_META_CONVERT))
typedef struct _GstGvaMetaConvert GstGvaMetaConvert;
typedef struct _GstGvaMetaConvertClass GstGvaMetaConvertClass;

typedef void (*convert_function_type)(GstGvaMetaConvert *converter, GstBuffer *buffer);

struct _GstGvaMetaConvert {
    GstBaseTransform base_gvametaconvert;

    gchar *model;
    gchar *converter;
    gchar *method;
    gchar *source;
    gchar *tags;
    gchar *attribute_name;
    gboolean include_no_detections;
    gchar *layer_name;
    gchar *inference_id;
    gfloat threshold;
    gboolean signal_handoffs;
    convert_function_type convert_function;
    gchar *location;
    GstVideoInfo *info;
};

struct _GstGvaMetaConvertClass {
    GstBaseTransformClass base_gvametaconvert_class;

    void (*handoff)(GstElement *element, GstBuffer *buf);
};

GType gst_gva_meta_convert_get_type(void);

G_END_DECLS

#endif
