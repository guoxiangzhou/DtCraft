/******************************************************************************
 *                                                                            *
 * Copyright (c) 2018, Tsung-Wei Huang, Chun-Xun Lin, and Martin D. F. Wong,  *
 * University of Illinois at Urbana-Champaign (UIUC), IL, USA.                *
 *                                                                            *
 * All Rights Reserved.                                                       *
 *                                                                            *
 * This program is free software. You can redistribute and/or modify          *
 * it in accordance with the terms of the accompanying license agreement.     *
 * See LICENSE in the top-level directory for details.                        *
 *                                                                            *
 ******************************************************************************/

#include <dtc/exit.hpp>

namespace dtc {

std::string status_to_string(int status) {

  using namespace std::literals::string_literals;

  if(WIFEXITED(status)) {
    switch(auto code = WEXITSTATUS(status); code) {

      case EXIT_SUCCESS:
        return "exited successfully";
      break;

      case EXIT_BROKEN_CONNECTION:
        return "borken connection";
      break;

      case EXIT_CRITICAL_STREAM:
        return "critical stream reached";
      break;
      
      case EXIT_CONTAINER_EXEC_FAILED:
        return "container exec failed";
      break;
      
      case EXIT_VERTEX_EXEC_FAILED:
        return "vertex exec failed";
      break;

      case EXIT_FAILURE:
        return "exited with failure";
      break;

      default:
        return "exited with unknown code: "s + std::to_string(code);
      break;
    };
  }
  else if(WIFSIGNALED(status)) {
    return "signaled "s + strsignal(WTERMSIG(status));
  }
  else {
    return "unknow status";
  }
}

};  // End of namespace dtc. ----------------------------------------------------------------------


