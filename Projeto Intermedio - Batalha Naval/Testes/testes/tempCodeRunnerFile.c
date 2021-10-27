void modo_p2(){
        int n_pecas_total, n_pecas_max, matriz_x, matriz_y, x, y, selecao_tipo, variante, tentativa_v=-1, i, j, tentativa_p[9]={0}, n_peca[9]={0}, i_tabuleiro=0, erro_tabuleiro=0, erro_peca=0, e_v=0;
    
        n_pecas_total= peca_n[1]+peca_n[2]+peca_n[3]+peca_n[4]+peca_n[5]+peca_n[6]+peca_n[7]+peca_n[8];
        n_pecas_max=((dim_tabu_x*dim_tabu_y)/9)/2;
        peca_n[0]= ((dim_tabu_x*dim_tabu_y)/9) - n_pecas_total;

        if (n_pecas_total>n_pecas_max){
            printf("\n-1 : O número de peças excedeu o número máximo de peças da matriz.\n\n");instrucoes();
        }
        do{ memset(yx,'-',sizeof(yx));
            matriz_y=-1;
            erro_tabuleiro=0;
            for(i=0;i<=8;i++){n_peca[i]=peca_n[i];}
            
            do{
              matriz_x=-1;
              matriz_y++;
              y=dim_tabu_y-(matriz_y*3);
                do{
                 for(j=0;j<=8;j++){tentativa_p[j]=0;}
                 matriz_x++;
                 x=1+(matriz_x*3);
                 tentativa_v=-1; 
                    do{ 
                        erro_peca=0;
                        selecao_tipo = rand() % 9;
                            
                        if ((n_peca[0]==0 || tentativa_p[0]==1) && (n_peca[1]==0 || tentativa_p[1]==1) && (n_peca[2]==0 || tentativa_p[2]==1) && (n_peca[3]==0 || tentativa_p[3]==1) && (n_peca[4]==0 || tentativa_p[4]==1) && (n_peca[5]==0 || tentativa_p[5]==1) &(n_peca[6]==0 || tentativa_p[6]==1) &(n_peca[7]==0 || tentativa_p[7]==1) && (n_peca[8]==0 || tentativa_p[8]==1) ){i_tabuleiro++;erro_tabuleiro=1;}
                        if (tentativa_p[selecao_tipo]==1){erro_peca=1;}
                        else{
                            if(selecao_tipo==0 && n_peca[0] != 0){
                                n_peca[0]--; e_v=0;
                            }
                            else if (selecao_tipo == 1 && n_peca[1] != 0){
                                do{ 
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 9;}
                                    switch(variante){
                                        case 0:
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' ){
                                                yx[y][x] = '1'; n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                        break;
                                        case 1: 
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                                yx[y][x+1] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 2:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y][x+2] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 3:
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' ){
                                                yx[y-1][x] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 4: 
                                            yx[y-1][x+1] = '1';n_peca[1]--;
                                            break;
                                        case 5: 
                                            if (yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y-1][x+2] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 6: 
                                        if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' ){
                                                yx[y-2][x] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 7: 
                                        if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y-2][x+1] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 8: 
                                            if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y-2][x+2] = '1';n_peca[1]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                    }
                                    if(tentativa_v>=8){erro_peca=1;tentativa_p[1]=1;}
                                }while (tentativa_v<8 && e_v==1 );
                            }
                            else if (selecao_tipo == 2 && n_peca[2] != 0){
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 12;}
                                    switch(variante){
                                        case 0:
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'  ){
                                                yx[y][x] = '2';yx[y][x+1] = '2';n_peca[2]--;
                                            } 
                                            else {e_v=1;}
                                            break;
                                        case 1:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-'   ){
                                                yx[y][x+1] = '2';yx[y][x+2] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 2:
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-'  ){
                                                yx[y-1][x] = '2';yx[y-1][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3:
                                            if (yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'  ){
                                                yx[y-1][x+1] = '2';yx[y-1][x+2] = '2';n_peca[2]--;
                                            } 
                                            else {e_v=1;} 
                                            break;
                                        case 4:
                                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'  ){
                                                yx[y-2][x] = '2';yx[y-2][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 5:
                                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-'   ){
                                                    yx[y-2][x+1] = '2';yx[y-2][x+2] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 6:
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-'  ){
                                                yx[y][x] = '2';yx[y-1][x] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 7:
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  ){
                                                yx[y-1][x] = '2';yx[y-2][x] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 8:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'  ){
                                                yx[y][x+1] = '2';yx[y-1][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 9:
                                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'  ){
                                                yx[y-1][x+1] = '2';yx[y-2][x+1] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 10:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'  ){
                                                yx[y][x+2] = '2';yx[y-1][x+2] = '2';n_peca[2]--;
                                            } 
                                            else {e_v=1;} 
                                            break;
                                        case 11:
                                        if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'  ){
                                            yx[y-1][x+2] = '2';yx[y-2][x+2] = '2';n_peca[2]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                    }
                                    if(tentativa_v>=11){erro_peca=1;tentativa_p[2]=1;}
                                }while (tentativa_v<11 && e_v==1 );  
                            }

                            else if (selecao_tipo == 3 && n_peca[3] != 0){
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 6;}
                                    switch(variante){
                                        case 0:
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y][x] = '3';yx[y][x+1] = '3';yx[y][x+2] = '3';n_peca[3]--;
                                            }else {e_v=1;} 
                                            break;
                                        case 1: 
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y-1][x] = '3';yx[y-1][x+1] = '3';yx[y-1][x+2] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 2: 
                                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){
                                                yx[y-2][x] = '3';yx[y-2][x+1] = '3';yx[y-2][x+2] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3: 
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'){
                                                yx[y][x] = '3';yx[y-1][x] = '3';yx[y-2][x] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 4:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y][x+1] = '3';yx[y-1][x+1] = '3';yx[y-2][x+1] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 5: 
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' ){
                                                yx[y][x+2] = '3';yx[y-1][x+2] = '3';yx[y-2][x+2] = '3';n_peca[3]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                    }       
                                    if(tentativa_v>=5){erro_peca=1;tentativa_p[3]=1;}
                                }while (tentativa_v<5 && e_v==1 );
                            }

                            else if (selecao_tipo == 4 && n_peca[4] != 0){
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 4;} 
                                    switch(variante){
                                        case 0:
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                                yx[y][x] = '4';yx[y][x+1] = '4';yx[y-1][x] = '4';yx[y-1][x+1] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1:
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y][x+1] = '4';yx[y][x+2] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 2: 
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-2][x] = '4';yx[y-2][x+1] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3: 
                                            if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' ){
                                                yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x+1] = '4';yx[y-2][x+2] = '4';n_peca[4]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa_p[4]=1;}
                                }while (tentativa_v<3 && e_v==1 );
                            }

                            else if (selecao_tipo == 5 && n_peca[5] != 0){
                                do{
                                    if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                    else{variante= rand() % 4;}
                                    switch(variante){
                                        case 0: 
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){
                                                yx[y][x] = '5';yx[y][x+1] = '5';yx[y][x+2] = '5';yx[y-1][x+1] = '5';yx[y-2][x+1] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1: 
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){
                                                yx[y][x] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 2: 
                                            if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){
                                                yx[y][x+1] = '5';yx[y-1][x+1] = '5';yx[y-2][x] = '5';yx[y-2][x+1] = '5';yx[y-2][x+2] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;} 
                                            break;
                                        case 3:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){
                                                yx[y][x+2] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x+2] = '5';n_peca[5]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa_p[5]=1;}
                                }while (tentativa_v<3 && e_v==1 );
                            }

                            else if (selecao_tipo == 6 && n_peca[6] != 0){
                                do{
                                if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                else{variante= rand() % 4;}
                                    switch(variante){
                                        case 0:
                                            if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){
                                                    yx[y][x+1] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';n_peca[6]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1: 
                                            if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' ){
                                                yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';n_peca[6]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 2: 
                                            if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x+1] = '6';n_peca[6]--;
                                            } 
                                            else {e_v=1;} 
                                            break;
                                        case 3: 
                                            if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){
                                                yx[y][x] = '6';yx[y][x+1] = '6';yx[y-1][x] = '6';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';n_peca[6]--;
                                                }
                                                else {e_v=1;} 
                                                break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa_p[6]=1;}
                                }while (tentativa_v<3 && e_v==1 );
                            }

                            else if (selecao_tipo == 7 && n_peca[7] != 0){
                                do{
                                if(e_v==1){tentativa_v++; variante=tentativa_v;e_v=0;}
                                else{variante= rand() % 2;}
                                   switch(variante){
                                        case 0:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){
                                                yx[y][x] = '7';yx[y][x+2] = '7';yx[y-1][x] = '7';yx[y-1][x+1] = '7';yx[y-1][x+2] = '7';yx[y-2][x] = '7';yx[y-2][x+2] = '7';n_peca[7]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                        case 1:
                                            if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){
                                                    yx[y][x] = '7';yx[y][x+1] = '7';yx[y][x+2] = '7';yx[y-1][x+1] = '7';yx[y-2][x] = '7';yx[y-2][x+1] = '7';yx[y-2][x+2] = '7';n_peca[7]--;
                                            }
                                            else {e_v=1;}
                                            break;
                                    }       
                                    if(tentativa_v>=2){erro_peca=1;tentativa_p[7]=1;}
                                }while (tentativa_v<2 && e_v==1 );
                            }

                            else if (selecao_tipo == 8 && n_peca[8] != 0){
                                if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){
                                    yx[y][x] = '8';yx[y][x+1] = '8';yx[y][x+2] = '8';yx[y-1][x] = '8';yx[y-1][x+2] = '8';yx[y-2][x] = '8';yx[y-2][x+1] = '8';yx[y-2][x+2] = '8';n_peca[8]--;
                                    } 
                                    else {erro_peca=1;tentativa_p[8]=1;} 
                            } 

                            else{erro_peca=1;}
                        }
                    }while(erro_peca==1 && erro_tabuleiro==0);  

                }while(x< dim_tabu_x - 2 && erro_tabuleiro==0);
            }while(y>3 && erro_tabuleiro==0 );
        }while(i_tabuleiro<1000 && erro_tabuleiro==1);
        
        if(i_tabuleiro==1000){printf("\n-1 : Não foi possível gerar o tabuleiro.\n\n");exit(1);}
    }