//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_BADGUY_FLAME_HPP
#define HEADER_SUPERTUX_BADGUY_FLAME_HPP

#include "badguy/badguy.hpp"

#include "audio/sound_source.hpp"

class Flame : public BadGuy
{
public:
  Flame(const ReaderMapping& reader);
  Flame(const Flame& flame);

  void activate();
  void deactivate();

  void active_update(float elapsed_time);
  void kill_fall();

  void freeze();
  bool is_freezable() const;
  bool is_flammable() const;

  ObjectSettings get_settings();
  virtual std::string get_class() const {
    return "flame";
  }
  std::string get_display_name() const {
    return _("Flame");
  }

  void stop_looping_sounds();
  void play_looping_sounds();

protected:
  float angle;
  float radius;
  float speed;

  std::unique_ptr<SoundSource> sound_source;
};

#endif

/* EOF */
