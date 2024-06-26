/*
 * SPDX-FileCopyrightText: 2016-2016 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 */
#ifndef _FCITX_MODULES_WAYLAND_WAYLAND_PUBLIC_H_
#define _FCITX_MODULES_WAYLAND_WAYLAND_PUBLIC_H_

#include <functional>
#include <memory>
#include <fcitx-utils/handlertable.h>
#include <fcitx-utils/metastring.h>
#include <fcitx/addoninstance.h>
#include <fcitx/focusgroup.h>
#include <wayland-client-protocol.h>
#include <wayland-client.h>

namespace fcitx {

using WaylandConnectionCreated =
    std::function<void(const std::string &, wl_display *, FocusGroup *)>;
using WaylandConnectionClosed =
    std::function<void(const std::string &, wl_display *)>;
} // namespace fcitx

FCITX_ADDON_DECLARE_FUNCTION(
    WaylandModule, addConnectionCreatedCallback,
    std::unique_ptr<HandlerTableEntry<fcitx::WaylandConnectionCreated>>(
        WaylandConnectionCreated));
FCITX_ADDON_DECLARE_FUNCTION(
    WaylandModule, addConnectionClosedCallback,
    std::unique_ptr<HandlerTableEntry<fcitx::WaylandConnectionClosed>>(
        WaylandConnectionClosed));
FCITX_ADDON_DECLARE_FUNCTION(WaylandModule, reloadXkbOption, void());
FCITX_ADDON_DECLARE_FUNCTION(WaylandModule, openConnection,
                             bool(const std::string &));
FCITX_ADDON_DECLARE_FUNCTION(WaylandModule, openConnectionSocket, bool(int fd));
FCITX_ADDON_DECLARE_FUNCTION(WaylandModule, reopenConnectionSocket,
                             bool(const std::string &name, int fd));
FCITX_ADDON_DECLARE_FUNCTION(WaylandModule, repeatInfo,
                             std::optional<std::tuple<int32_t, int32_t>>(
                                 const std::string &name, wl_seat *));

#endif // _FCITX_MODULES_WAYLAND_WAYLAND_PUBLIC_H_
