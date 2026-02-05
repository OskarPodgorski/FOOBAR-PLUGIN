#pragma once

#include "foo_sdk/foobar2000/SDK/foobar2000.h"
#include "foo_sdk/foobar2000/SDK/preferences_page.h"

static const GUID guid =
{ 0xe7bba981, 0x4a3c, 0x4f23, { 0xb1, 0x23, 0x12, 0x34, 0xab, 0xcd, 0xef, 0x00 } };

class pref_page : public preferences_page_v3 {
public:
    const char* get_name() override { return "testOSD"; }
    GUID get_guid() override { return guid; }
    GUID get_parent_guid() override { return guid_tools; }

    preferences_page_instance::ptr instantiate(fb2k::hwnd_t parent, preferences_page_callback::ptr callback) override {
        return fb2k::service_new<pref_page>(parent, callback);
    }
};

static preferences_page_factory_t<pref_page> g_testOSDFactory;
