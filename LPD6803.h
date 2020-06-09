#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/*!
 * @brief Class that stores state and functions for interacting with LPD6803 RGB
 * Pixels
 */
class LPD6803 {
private:
  uint8_t cpumax;

public:
  /*!
   * @brief LPD6803 constructor
   * @param n Number of pixels
   * @param dpin Data pin
   * @param cpin Clock pin
   */
  LPD6803(uint16_t n, uint8_t dpin, uint8_t cpin);
  void begin(); //!< Starts I2C connection
  void show();  //!< Shows pixels on LEDs
  /*!
   * @brief Update the pixels when next possible
   * @param idx Which LED we are updating
   */
  void doSwapBuffersAsap(uint16_t idx);
  /*!
   * @brief Set a pixel's color using separate red, green and blue components
   * @param n Pixel index, starting from 0
   * @param r Red brightness, 0 = minimum (off), 255 = maximum
   * @param g Green brightness, 0 = minimum (off), 255 = maximum
   * @param b Blue brightness, 0 = minimum (off), 255 = maximum
   */
  void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
  /*!
   * @brief Set a pixel's color using a 32-bit 'packed' RGB or RGBW value.
   * @param n Pixel index, starting from 0.
   * @param c 32-bit color value. Most significant byte is white (for RGBW
   *          pixels) or ignored (for RGB pixels), next is red, then green,
   *          and least significant byte is blue
   */
  void setPixelColor(uint16_t n, uint16_t c);
  /*!
   * @brief Sets max cpu speed
   * @param m max CPU clock speed, in MHz
   */
  void setCPUmax(uint8_t m);
  /*!
   * @brief Number of pixels connected
   * @return Returns a 16-bit signed int equal to how many pixels are connected
   */
  uint16_t numPixels(void);
};
