#include <pebble.h>

static Window *s_main_window;
static TextLayer *s_time_layer;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;

// Color cycling feature - commented out for v1.0 release
/*
static int color_index = 2; // Default to cyan
static const int NUM_COLORS = 4;

static GColor get_color(int index) {
  switch(index) {
    case 0: return GColorWhite;
    case 1: return GColorGreen;
    case 2: return GColorCyan;
    case 3: return GColorOrange;
    default: return GColorCyan;
  }
}
*/




static void update_time() {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  
  static char s_buffer[8];
  strftime(s_buffer, sizeof(s_buffer), "%I:%M", tick_time);
  text_layer_set_text(s_time_layer, s_buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

// Color cycling functions - commented out for v1.0 release
/*
static void update_color() {
  text_layer_set_text_color(s_time_layer, get_color(color_index));
  persist_write_int(1, color_index);
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  color_index = (color_index + 1) % NUM_COLORS;
  update_color();
  vibes_short_pulse();
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}
*/



static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  window_set_background_color(window, GColorBlack);
  
  s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CORTANA_BG);
  if (s_background_bitmap) {
    s_background_layer = bitmap_layer_create(bounds);
    bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
    bitmap_layer_set_compositing_mode(s_background_layer, GCompOpSet);
    bitmap_layer_set_alignment(s_background_layer, GAlignCenter);
    layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));
  }
  
  s_time_layer = text_layer_create(GRect(0, 60, bounds.size.w, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorCyan);
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  
  // Color cycling click handler - commented out for v1.0 release
  // window_set_click_config_provider(window, click_config_provider);
}

static void main_window_unload(Window *window) {
  text_layer_destroy(s_time_layer);
  if (s_background_layer) {
    bitmap_layer_destroy(s_background_layer);
  }
  if (s_background_bitmap) {
    gbitmap_destroy(s_background_bitmap);
  }
}

static void init() {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  

  
  // Color preference loading - commented out for v1.0 release
  /*
  if (persist_exists(1)) {
    color_index = persist_read_int(1);
    if (color_index < 0 || color_index >= NUM_COLORS) {
      color_index = 2; // Default to cyan
    }
  }
  */
  

  
  window_stack_push(s_main_window, true);
  
  update_time();
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void deinit() {
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
