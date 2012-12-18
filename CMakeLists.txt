cmake_minimum_required (VERSION 2.8.10)
project (pbtemplate)

include (pixelboost/build.cmake)

pixelboost_setup_pre(pixelboost pbtemplate "com.pixelboost.template" "Pixelboost Template")

include_directories("source")

set (GAME_SOURCES
	"source/game/game.cpp"
	)

pixelboost_setup_post()
