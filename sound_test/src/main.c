#include <SDL.h>
#include <stdio.h>

Uint32 audioLen, audioPos;

void audioCallBack(void *udata, Uint8 *stream, int len)
{
    // On ne lit que s'il reste des données à jouer
    if ( audioLen == 0 )
        return;

    // Remise à zéro du tampon de sortie
    memset(stream, 0, len);

    // Lecture du buffer audio
    if (audioPos < audioBufferSpec.len) {
        if (audioPos+len > audioBufferSpec.len)
            len = audioBufferSpec.len = audioPos;
        SDL_MixAudio(stream, audioBuffer + audioPos,
            len, SDL_MIX_MAXVOLUME);
        audioPos += len;
    }

    // Décrémentation de ce qu'il reste à lire
    audioLen -= len;
}

void audio_Init(SDL_AudioSpec *element)
{
    // Définition des propriétés audio
    element->freq = 22050;
    element->format = AUDIO_S16;
    element->channels = 2;
    element->samples = 1024;
    element->callback = audioCallBack;
    element->userdata = NULL;
}

int	main(int argc, char *argv[])
{
	// SDL_Window *window = NULL;
	// SDL_Renderer *renderer = NULL;
	SDL_AudioSpec	audio_a;
	SDL_AudioSpec	audio_b;
	SDL_AudioSpec	audio_c;
	Uint8	*test_a;
	Uint32	test_b;

	SDL_Init(SDL_INIT_AUDIO);
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
		exit (EXIT_FAILURE);
/*========================================*/
	audio_Init(&audio_a);
/*========================================*/
	SDL_OpenAudio(&audio_a, &audio_b);
/*========================================*/
	if(!SDL_LoadWAV("march_ahead.wav", &audio_c, &test_a, &test_b))
		exit (EXIT_FAILURE);
	// audioCallBack(&test_b, test_a, 1024);
	SDL_Delay(5000);
	SDL_FreeWAV(&test_a);




	// SDL_PauseAudio(0);
	// window = SDL_CreateWindow("Fentre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	// if (window == NULL)
	// 	exit (EXIT_FAILURE);
	// renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	// if (renderer == NULL)
	// 	exit (EXIT_FAILURE);
	// SDL_RenderPresent(renderer);
	// if(SDL_RenderClear(renderer))
	// 	exit (EXIT_FAILURE);

	// SDL_Delay(5000);
	// SDL_DestroyRenderer(renderer);
	// SDL_DestroyWindow(window);
	SDL_Quit();

	SDL_version	nb;
	SDL_VERSION(&nb);

	printf("SDL %d.%d.%d\n", nb.major, nb.minor, nb.patch);
	return (0);
}
