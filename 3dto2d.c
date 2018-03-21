#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  FILE* fp   = fopen("copy.ply","r"); 
  FILE* fout = fopen("copyflat.ply","w");
  
  char line[200];
  char tmp[200];
  
  
  if(fp!=NULL){
    int i;
    int coord = 0;
    char* token[6];
    
    for(i=0;i<6;i++){
      token[i] = (char *)malloc(15); 
    }

    while(fgets(line,200,fp) != '\0'){
      if(coord ==1){
        token[0] = strtok(line," ");
      
        for(i=1 ; i<6; i++)
          token[i] = strtok(NULL," ");

//        printf("token0 %s\n",token[0]); 

  //      printf("token1 %s\n",token[1]);
        token[2] = "0";
    //    printf("token2 %s\n",token[2]);

        sprintf(line,"%s %s %s %s %s %s",token[0],token[1],token[2],token[3],token[4],token[5]);
      //  printf("%s\n",line); 
        fputs(line,fout);
      }
      else if(strcmp(line,"end_header\n")==0){
        fputs(line,fout);
        coord =1;}
      else 
        fputs(line,fout);
    }
    fclose(fp);
    fclose(fout);
  }
  return 0;
}
