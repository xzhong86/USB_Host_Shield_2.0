
add_compile_definitions(__RP2040__)
add_library(usb_host_shield
  Usb.cpp usbhid.cpp usbhub.cpp parsetools.cpp message.cpp
  rp2040-ard.cpp
  )

target_link_libraries(usb_host_shield pico_stdlib hardware_spi)

target_include_directories(usb_host_shield PUBLIC .)
