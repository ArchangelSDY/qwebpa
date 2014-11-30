add_definitions(
    -DQT_PLUGIN
    -DQT_NO_DEBUG
)

# set all include directories for in and out of source builds
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec
    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc
    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp
    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/mux
    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/webp
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(WEBP_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/alpha.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/buffer.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/frame.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/idec.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/io.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/layer.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/quant.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/tree.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/vp8.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/vp8l.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dec/webp.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/demux/demux.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/cpu.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/dec.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/dec_neon.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/dec_sse2.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/enc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/enc_neon.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/enc_sse2.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/lossless.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/upsampling.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/upsampling_neon.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/upsampling_sse2.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/dsp/yuv.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/alpha.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/analysis.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/backward_references.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/config.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/cost.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/filter.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/frame.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/histogram.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/iterator.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/layer.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/picture.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/quant.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/syntax.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/token.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/tree.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/vp8l.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/enc/webpenc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/mux/muxedit.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/mux/muxinternal.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/mux/muxread.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/alpha_processing.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/bit_reader.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/bit_writer.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/color_cache.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/filters.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/huffman.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/huffman_encode.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/quant_levels.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/quant_levels_dec.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/random.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/rescaler.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/thread.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/libwebp/src/utils/utils.c"
)

set(SRCS "main.cpp" "qwebphandler.cpp" ${WEBP_SRC})
set(CMAKE_AUTOMOC ON)

add_library(qwebpa SHARED ${SRCS})
set_target_properties(qwebpa PROPERTIES VERSION 1.0.0 SOVERSION 1)
set_target_properties(qwebpa PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/imageformats")
target_link_libraries(qwebpa Qt5::Core Qt5::Gui)

set(LIB_DESTINATION "plugins/imageformats")
install(TARGETS qwebpa LIBRARY DESTINATION ${LIB_DESTINATION} ARCHIVE DESTINATION ${LIB_DESTINATION} RUNTIME DESTINATION ${LIB_DESTINATION})
