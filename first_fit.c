// First Fit Paging Algorithm

#include <stdio.h>
#define max 25

void main() {
    int frag[max], block_size[max], file[max], file_size[max];
    int i,j,k, nb, nf;
    
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    
    printf("Enter the size of each block\n");
    for (i=0; i<nb; i++){
        printf("Size of block %d: ", i+1);
        scanf("%d", &block_size[i]);
    }
    
    printf("\nEnter the number of files: ");
    scanf("%d", &nf);
    
    printf("Enter the size of each file\n");
    for(i=0; i<nf; i++){
        printf("Size of file %d: ", i+1);
        scanf("%d", &file_size[i]);
    }
    
    for(i=0;i<nf;i++){
        file[i]=0;
    }
    
    for(i=0; i<nf; i++){
        for (j=0; j<nb; j++){
            if(file_size[i]<=block_size[j]){
                frag[i] = block_size[j]-file_size[i];
                block_size[j] = block_size[j]-file_size[i];
                file[i]=j+1;
                break;
            }
        }
    }
    for(i=0;i<nf;i++){
        if (file[i]==0){
            printf("\nFile %d is in the waiting queue", i+1);
        }
        else{
            printf("\nFile %d is at %d block with fragment of %d", i+1, file[i], frag[i]);
        }
    }
    
}
