// Created by moisrex on 6/18/24.

module;

#include <libevdev/libevdev.h>
#include <string_view>

export module foresight.evdev;

/**
 * This is a wrapper for libevdev's related features
 */
export struct evdev {
    explicit evdev(std::string_view file);
    explicit evdev(int file_descriptor);
             evdev(evdev&&)          = default;
             evdev(evdev const&)     = delete;
    evdev&   operator=(evdev const&) = delete;
    evdev&   operator=(evdev&&)      = default;
    ~        evdev();

    /// check if everything is okay
    [[nodiscard]] bool ok() const noexcept {
        return dev == nullptr;
    }

    /**
     * Retrieve the device's name, either as set by the caller or as read from
     * the kernel. The string returned is valid until libevdev_free() or until
     * libevdev_set_name(), whichever comes earlier.
     */
    [[nodiscard]] std::string_view device_name() const noexcept;

  private:
    libevdev* dev = nullptr;
};