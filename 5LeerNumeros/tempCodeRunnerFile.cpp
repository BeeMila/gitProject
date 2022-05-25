 }else if(c == 8){ //Si el input es un back space
			system("CLS");
            cout<< i <<endl;
            imprimirMensaje(mensaje);
            for(int p = 0; p < i-1; p++){
                printf("%c", dato[p]);
            }

			if(i != 0){
                if(dato[i-1] == 46){
                    conversion.setFlotante(0);
                    j = 0;
                }
				dato[--i]='\0';
                --i;
			}
        }  