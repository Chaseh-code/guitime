#ifndef GUITIME_H
#define GUITIME_H

#include <memory>  // for allocator, __shared_ptr_access, shared_ptr
#include <string>  // for string, basic_string
#include <vector>  // for vector

#include "mathOperations.h" // Temp for testing. Need to test how I can create dom & components and pass them back to main for rendering

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Radiobox, Renderer, Tab, Toggle, Vertical
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for Element, separator, operator|, vbox, border

using namespace ftxui;

int guitime();

int guitime() {

 std::string output ="";

 std::vector<std::string> tab_values{
      "Tab_1",
      "Tab_2",
      "Tab_3",
      "Tab_4",
  };
  int tab_selected = 0;
  auto tab_toggle = Toggle(&tab_values, &tab_selected);

  std::vector<std::string> tab_1_entries{
      "Add",
      "Subtract",
      "Multiply",
      "Divide",
      "Exit",
  };
  int tab_1_selected = 0;

  /*std::vector<std::string> tab_2_entries{
      "Hello",
      "Hi",
      "Hay",
  };
  int tab_2_selected = 0;

  std::vector<std::string> tab_3_entries{
      "Table",
      "Nothing",
      "Is",
      "Empty",
  };
  int tab_3_selected = 0;
  */
  auto tab_container = Container::Tab(
      {
          Radiobox(&tab_1_entries, &tab_1_selected),
          /*Radiobox(&tab_2_entries, &tab_2_selected),
          Radiobox(&tab_3_entries, &tab_3_selected),*/
      },
      &tab_selected);

  auto container = Container::Vertical({
      tab_toggle,
      tab_container,
  });

    // Need to figure out how to redraw the screen with the selected toggle output value selected
    switch(tab_1_selected) {
        case 0: output=std::to_string(add()); break;
        case 1: subtract(); break;
        case 2: multiply(); break;
        case 3: divide(); break;
        default: exit(0);
    }

  auto renderer = Renderer(container, [&] {
    return vbox({
               tab_toggle->Render(),
               separator(),
               tab_container->Render(),
               text(output), // Maybe need something different than just text. Make a bordered section that gets updated from the selected toggle option.
           }) |
           border;
  });

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);

    //return 0;
    return tab_1_selected;
}

#endif