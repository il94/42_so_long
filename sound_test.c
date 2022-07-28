 #include <stdio.h>
 #include <stdlib.h>
 #include <vlc/vlc.h>
 

/* apt-get install libvlccore-dev libvlc-dev */

 static void quit_on_exception (libvlc_exception_t *excp) {
    if (libvlc_exception_raised (excp)) {
       fprintf(stderr, "error: %s\n", libvlc_exception_get_message(excp));
       exit(-1);
    }
 }
 
 int main(int argc, char **argv) {
    libvlc_exception_t excp;
    libvlc_instance_t *inst;
    int item;
    char *filename = "./myFile.mp3";
 
    libvlc_exception_init (&excp);
    inst = libvlc_new (argc, argv, &excp);
    quit_on_exception (&excp);
    item = libvlc_playlist_add (inst, filename, NULL, &excp); 
    quit_on_exception (&excp);
    libvlc_playlist_play (inst, item, 0, NULL, &excp); 
    quit_on_exception (&excp);
    usleep (10000000);
    libvlc_destroy (inst);
    return 0;
 }