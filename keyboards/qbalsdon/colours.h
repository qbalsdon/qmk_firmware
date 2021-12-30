#ifndef __colours_h
#define __colours_h

bool layer_changed_recently = false;
uint16_t layer_change_timer = 0;

#define ANIMATION_FRAMES 32
uint16_t animation_time = 0;
uint16_t animation_frame = 0;
int colourReference = 0;
int flashIndex = -1;

void keyboard_post_init_user(void) {
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_setrgb(0,0,0);
}

uint16_t* getRainbowColourForIndex(int index)
{
  static uint16_t colour[3];

  switch (index % 16) {
    case 1:  colour[0] = 0xC2; colour[1] = 0x18; colour[2] = 0x5B; break;
    case 2:  colour[0] = 0x7B; colour[1] = 0x1F; colour[2] = 0xA2; break;
    case 3:  colour[0] = 0x51; colour[1] = 0x2D; colour[2] = 0xA8; break;
    case 4:  colour[0] = 0x30; colour[1] = 0x3F; colour[2] = 0x9F; break;
    case 5:  colour[0] = 0x19; colour[1] = 0x76; colour[2] = 0xD2; break;
    case 6:  colour[0] = 0x02; colour[1] = 0x88; colour[2] = 0xD1; break;
    case 7:  colour[0] = 0x00; colour[1] = 0x97; colour[2] = 0xA7; break;
    case 8:  colour[0] = 0x00; colour[1] = 0x79; colour[2] = 0x6B; break;
    case 9:  colour[0] = 0x38; colour[1] = 0x8E; colour[2] = 0x3C; break;
    case 10: colour[0] = 0x68; colour[1] = 0x9F; colour[2] = 0x38; break;
    case 11: colour[0] = 0xAF; colour[1] = 0xB4; colour[2] = 0x2B; break;
    case 12: colour[0] = 0xFB; colour[1] = 0xC0; colour[2] = 0x2D; break;
    case 13: colour[0] = 0xFF; colour[1] = 0xA0; colour[2] = 0x00; break;
    case 14: colour[0] = 0xF5; colour[1] = 0x7C; colour[2] = 0x00; break;
    case 15: colour[0] = 0xE6; colour[1] = 0x4A; colour[2] = 0x19; break;
    default: colour[0] = 0xd3; colour[1] = 0x2f; colour[2] = 0x2f;
  }
  return colour;
}

void updateAnimationFrame(uint16_t* animated_colour, uint16_t* bar_colour) {
    if (timer_read() - animation_time < 50) {
      return;
    }
    animation_frame = (animation_frame + 1) % ANIMATION_FRAMES;
    animation_time = timer_read();
    flashIndex = (flashIndex + 1) % RGBLED_NUM;

    for (int i = 0; i < RGBLED_NUM; i++) {
        if (i >= flashIndex - 1 && i <= flashIndex + 1) {
            rgblight_setrgb_at(animated_colour[0], animated_colour[1], animated_colour[2], i);
        } else {
            rgblight_setrgb_at(bar_colour[0], bar_colour[1], bar_colour[2], i);
        }
    }
}

#endif // __colours_h
