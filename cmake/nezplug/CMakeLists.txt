cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME nezplug)
project (${TARGET_NAME})

set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(GLOBAL_SRC_DIR ${BASE_DIR})

# add_subdirectory(cpu/kmz80)

set(src_list 
	${BASE_DIR}/src/ChMask.cpp
	${BASE_DIR}/src/common/nsfsdk/nsfsdk.c
	# ${BASE_DIR}/src/common/nsfsdk/sample/nsf2wav.c
	# ${BASE_DIR}/src/common/unix/csounix.c
	# ${BASE_DIR}/src/common/win32/csowin32.c
	${BASE_DIR}/src/common/win32/win32dll.c
	${BASE_DIR}/src/cpu/kmz80/kmdmg.c
	${BASE_DIR}/src/cpu/kmz80/kmevent.c
	${BASE_DIR}/src/cpu/kmz80/kmr800.c
	${BASE_DIR}/src/cpu/kmz80/kmz80.c
	${BASE_DIR}/src/cpu/kmz80/kmz80c.c
	${BASE_DIR}/src/cpu/kmz80/kmz80t.c
	# ${BASE_DIR}/src/cpu/kmz80/makeft.c
	# ${BASE_DIR}/src/cpu/kmz80/test/kmhd180.c
	${BASE_DIR}/src/device/nes/logtable.c
	${BASE_DIR}/src/device/nes/s_apu.c
	${BASE_DIR}/src/device/nes/s_fds.c
	${BASE_DIR}/src/device/nes/s_fds1.c
	${BASE_DIR}/src/device/nes/s_fds2.c
	${BASE_DIR}/src/device/nes/s_fds3.c
	# ${BASE_DIR}/src/device/nes/s_fdse.c
	${BASE_DIR}/src/device/nes/s_fme7.c
	${BASE_DIR}/src/device/nes/s_mmc5.c
	${BASE_DIR}/src/device/nes/s_n106.c
	${BASE_DIR}/src/device/nes/s_vrc6.c
	${BASE_DIR}/src/device/nes/s_vrc7.c
	# ${BASE_DIR}/src/device/opl/ill/bin2c.c
	# ${BASE_DIR}/src/device/opl/ill_old/bin2c.c
	${BASE_DIR}/src/device/opl/s_deltat.c
	${BASE_DIR}/src/device/opl/s_opl.c
	${BASE_DIR}/src/device/opl/s_opltbl.c
	${BASE_DIR}/src/device/s_dmg.c
	${BASE_DIR}/src/device/s_hes.c
	${BASE_DIR}/src/device/s_hesad.c
	${BASE_DIR}/src/device/s_logtbl.c
	${BASE_DIR}/src/device/s_psg.c
	${BASE_DIR}/src/device/s_scc.c
	${BASE_DIR}/src/device/s_sng.c
	${BASE_DIR}/src/format/audiosys.c
	${BASE_DIR}/src/format/handler.c
	${BASE_DIR}/src/format/m_gbr.c
	${BASE_DIR}/src/format/m_hes.c
	${BASE_DIR}/src/format/m_kss.c
	${BASE_DIR}/src/format/m_nsd.c
	${BASE_DIR}/src/format/m_nsf.c
	${BASE_DIR}/src/format/m_sgc.c
	${BASE_DIR}/src/format/m_zxay.c
	${BASE_DIR}/src/format/nezplug.c
	${BASE_DIR}/src/format/nsf6502.c
	${BASE_DIR}/src/format/dumper.c
	${BASE_DIR}/src/format/songinfo.c
	# ${BASE_DIR}/src/snddrv/snddrv.c
	# ${BASE_DIR}/src/snddrv/win32/snddrvds.c
	# ${BASE_DIR}/src/snddrv/win32/snddrvwo.c
	# ${BASE_DIR}/src/ui/hsp/hspnez.c
	# ${BASE_DIR}/src/ui/kmp/kmp_com.c
	# ${BASE_DIR}/src/ui/kmp/kpinez.c
	${BASE_DIR}/src/ui/nezplug/ChMask.c
	${BASE_DIR}/src/ui/nezplug/Dialog.c
	${BASE_DIR}/src/ui/nezplug/Dump.c
	${BASE_DIR}/src/ui/nezplug/FileInfo.c
	${BASE_DIR}/src/ui/nezplug/IOView.c
	${BASE_DIR}/src/ui/nezplug/MemView.c
	# ${BASE_DIR}/src/ui/uty/m3u2pls/m3u2pls.c
	# ${BASE_DIR}/src/ui/winamp/con_nez.c
	# ${BASE_DIR}/src/ui/winamp/in_nez.c
	# ${BASE_DIR}/src/ui/winamp/seq_nez.c
	# ${BASE_DIR}/src/zlib/adler32.c
	# ${BASE_DIR}/src/zlib/compress.c
	# ${BASE_DIR}/src/zlib/crc32.c
	# ${BASE_DIR}/src/zlib/deflate.c
	# # ${BASE_DIR}/src/zlib/example.c
	# ${BASE_DIR}/src/zlib/gzio.c
	# ${BASE_DIR}/src/zlib/infback.c
	# ${BASE_DIR}/src/zlib/inffast.c
	# ${BASE_DIR}/src/zlib/inflate.c
	# ${BASE_DIR}/src/zlib/inftrees.c
	# ${BASE_DIR}/src/zlib/memzip.c
	# # ${BASE_DIR}/src/zlib/minigzip.c
	# ${BASE_DIR}/src/zlib/nez.c
	# ${BASE_DIR}/src/zlib/trees.c
	# ${BASE_DIR}/src/zlib/uncompr.c
	# ${BASE_DIR}/src/zlib/zutil.c
)

if(WIN32)
	set(extra_srcs  
		${BASE_DIR}/src/common/nsfsdk/npnez.def
		${BASE_DIR}/src/ui/nezplug/nezplug.rc
	)
else()
	message(FATAL_ERROR "currentry not supported")
endif()
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcommon -fno-zero-initialized-in-bss")
# Add an executable
add_library(${TARGET_NAME} SHARED ${src_list} ${extra_srcs})

target_link_options(${TARGET_NAME} PUBLIC LINKER:-Map=${TARGET_NAME}.map)

# 大きなグローバルバッファ変数の影響でbssセクションが膨らみバイナリサイズが増えてしまう
# target_link_options(${TARGET_NAME} PUBLIC LINKER:-fcommon -fno-zero-initialized-in-bss)
# target_compile_options(${TARGET_NAME} PUBLIC -fcommon -fno-zero-initialized-in-bss -v)
# ↑は効かなかった。グローバル変数を削除した。

# eh_handlerなどを削除する。十分に枯れているので大丈夫でしょう。
target_compile_options(${TARGET_NAME} PUBLIC -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables)
target_link_options(${TARGET_NAME} PUBLIC LINKER:-fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables)

target_link_options(${TARGET_NAME} PUBLIC LINKER: -static-libgcc)
target_link_options(${TARGET_NAME} PUBLIC LINKER: -Wl,-cref)

target_link_libraries(${TARGET_NAME} PRIVATE comdlg32 )
target_include_directories(${TARGET_NAME} PRIVATE ${BASE_DIR}/src)
target_include_directories(${TARGET_NAME} PRIVATE ${BASE_DIR}/src/cpu)

install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION bin)
