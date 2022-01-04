//#include "./src/utils/utils.h"
//#include "./src/elementRegistry.h"

//void eventSDL(SDL_Event event) {
//    switch (event.type) {
//        case SDL_QUIT: {
//            GlobalVariables.gameIsRunning = false;
//            break;
//        }
//        case SDL_MOUSEBUTTONDOWN: {
//            if (event.button.button == SDL_BUTTON_LEFT) {
//                s32 id = testForGUIs();
//                if (id != -1) GlobalVariables.currentMatID = id;
//                else GlobalVariables.holdingLeft = true;
//            } else if (event.button.button == SDL_BUTTON_RIGHT) {
//                // Vector2D tile = mouseToTile(GlobalVariables.mouse);
//                // Vector2D p = {tile.x, tile.y};
//
//                // GlobalVariables.shower.id = GlobalVariables.currentMatID;
//                // GlobalVariables.shower.pos = p;
//            }
//            break;
//        }
//        case SDL_MOUSEBUTTONUP: {
//            GlobalVariables.holdingLeft = false;
//            break;
//        }
//        default:
//            break;
//    }
//}

#include "src/utils/GlobalVariables.h"
#include "src/core/TextureManager.h"

int main() {
    GlobalVariables.init();

    GLFWwindow *window = GlobalVariables.displayManager->getWindow();
    for (int x = 0; x < DisplayManager::WIDTH; x++) {
        for (int y = 0; y < DisplayManager::HEIGHT; y++) {
            std::shared_ptr<Element> test = GlobalVariables.elementRegistry->getElement(randomVal(1, 2));
            GlobalVariables.world->setElement(x, y, test);
        }
    }

    std::cout << "Starting main loop!" << std::endl;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        unsigned int image = TextureManager::create2DTexture(DisplayManager::WIDTH, DisplayManager::HEIGHT,
                                                             GlobalVariables.world->worldBuffer);

        GlobalVariables.displayRenderer->render(image);
        GlobalVariables.displayManager->updateDisplay();

        glDeleteTextures(1, &image);
    }

    DisplayManager::cleanUp();
    return 0;
}

//	GlobalVariables.init();
//	SDL_Renderer* renderer = GlobalVariables.renderer;
//	SDL_Texture* texture = GlobalVariables.texture;
//	u32* pixels = GlobalVariables.pixels;
//
//	// GUIs
//	generateAllGUIs();
//
//	// Background
//	clearScreen(0x000000);
//
//	// FPS Things
//	clock_t current_ticks, delta_ticks;
//	s64 fps = 0;
//
//	SDL_Event event;
//	while (GlobalVariables.gameIsRunning) {
//		while (SDL_PollEvent(&event)) {
//			eventSDL(event);
//
//			Vector2D pos;
//			SDL_GetMouseState(&pos.x, &pos.y);
//
//            GlobalVariables.oldMouse.x = GlobalVariables.mouse.x;
//            GlobalVariables.oldMouse.y = GlobalVariables.mouse.y;
//
//            GlobalVariables.mouse.x = pos.x;
//            GlobalVariables.mouse.y = pos.y;
//		}
//
//		// Calculate FPS
//		current_ticks = clock();
//
//		// Update Frame
//		GlobalVariables.currentFrame++;
//
//		// Mouse Input
//		if (GlobalVariables.holdingLeft) {
//			Vector2D oldTile = mouseToTile(GlobalVariables.oldMouse);
//			Vector2D tile = mouseToTile(GlobalVariables.mouse);
//			s32 id = GlobalVariables.currentMatID;
//			if (id != STONE) {
//				if (GlobalVariables.currentFrame % 10 == 0) {
//					world.setRectPixel(tile.x, tile.y, 10, create_particle(id));
//				}
//			} else {
//				world.setCircleLine(oldTile.x, oldTile.y, tile.x, tile.y, 2, create_particle(id));
//			}
//		}
//
//		/*
//		if (GlobalVariables.shower.id != -1 && GlobalVariables.currentFrame % 6 == 0) {
//			s32 id = globalvariables.shower.id;
//			s32 x = globalvariables.shower.pos.x;
//			s32 y = globalvariables.shower.pos.y;
//			world.setElement(x, y, create_particle(id));
//		}
//		*/
//
//		// Clean
//		// clearScreen(0x000000);
//
//		// Update World
//		world.update();
//		world.render();
//
//		SDL_UpdateTexture(texture, NULL, pixels, GlobalVariables.screenWidth * sizeof(u32));
//		SDL_RenderCopy(renderer, texture, NULL, NULL);
//		SDL_RenderPresent(renderer);
//
//		// calculate fps
//		delta_ticks = clock() - current_ticks;
//		if (delta_ticks > 0) {
//			fps = CLOCKS_PER_SEC / delta_ticks;
//			// cout << "delta ticks: " << delta_ticks << " fps: " << fps << endl;
//		} else {
//			fps = (s64)INFINITY;
//		}
//	}
//
//	GlobalVariables.destroy();
//	return 0;
//}