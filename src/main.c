/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 * EnzOS Operating System
 */

#include "EnzOS/types.h"
#include "EnzOS/vesa.h"
#include "EnzOS/term.h"
#include "EnzOS/win.h"

Term *term;

int main(void) {
        Term t;

        term = &t;

        terminit(term);

        setVGAMode(VMODE);

        printf("Welcome to EnzOS\n");
        printf("Author: %s\n", "Tiago Natel de Moura");

        vesaInit();

/*        Win win;
        winInit(&win);

        strncpy(win.top, "EnzOS operating system", 80);
        strncpy(win.footer, "Tiago Natel de Moura", 80);
*/

        //winRender(&win);
}
