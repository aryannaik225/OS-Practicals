//Worst Fit Paging 

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
        frag[i]=0;
    }
    int temp, temp_pos;
    
    for (i=0;i<nf;i++){
        temp = -1;
        temp_pos = -1;
        for (j=0; j<nb; j++){
            if (block_size[j] >= file_size[i]){
                if (temp==-1)
                {
                    temp = block_size[j] - file_size[i];
                    temp_pos = j;
                }
                else {
                    if(temp<block_size[j]-file_size[i]){
                        temp = block_size[j] - file_size[i];
                        temp_pos = j;
                    }
                }
            }
        }
        if(temp!=-1){
            file[i]=temp_pos+1;
            frag[i]=temp;
            block_size[temp_pos] = temp;
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
