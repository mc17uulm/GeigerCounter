#include "Settings.h"

struct Settings* load_settings() {
    const char* ssid = StaticMemory::read(MemoryRegister::SSID);
    const char* password = StaticMemory::read(MemoryRegister::PASSWORD);
    const char* username = StaticMemory::read(MemoryRegister::API_USER);
    const char* token = StaticMemory::read(MemoryRegister::API_TOKEN);
    const char* endpoint = StaticMemory::read(MemoryRegister::API_ENDPOINT);

    struct APISettings* api = (struct APISettings*) malloc(sizeof(APISettings));
    struct Settings* settings = (struct Settings*) malloc(sizeof(Settings));

    api->username = username;
    api->token = token;
    api->endpoint_uri = endpoint;

    settings->ssid = ssid;
    settings->password = password;
    settings->auditive_counter = false;
    settings->api = api;

    return settings;
}

bool save_settings(struct Settings* settings) {

    struct APISettings* api = settings->api;
    StaticMemory::write(MemoryRegister::SSID, settings->ssid);
    StaticMemory::write(MemoryRegister::PASSWORD, settings->password);
    StaticMemory::write(MemoryRegister::AUDITIVE_COUNTER, String(settings->auditive_counter));
    StaticMemory::write(MemoryRegister::API_USER, api->username);
    StaticMemory::write(MemoryRegister::API_TOKEN, api->token);
    StaticMemory::write(MemoryRegister::API_ENDPOINT, api->endpoint_uri);

    return StaticMemory::save();

}