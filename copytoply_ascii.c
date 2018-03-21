#include<stdio.h>

int main(){

  FILE* fp = fopen("../odm_texturing/odm_textured_model_geo.obj","r");
  FILE* fout = fopen("copy.obj","w");
  printf("file");

  if(fp!=NULL){
    char tmp[200];
    
    fputs("ply\n
        format ascii 1.0\n
        element:",fout);

    while(fgets(tmp,200,fp)!= '\0'){
      if(tmp[0]=='v'){    // only vertex.
       // printf("%s",tmp);
        fputs(tmp,fout);
      }
      else continue;
    }
    fclose(fp);
    fclose(fout);
  }

  return 0;
}
