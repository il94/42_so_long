#include <SDL.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	SDL_AudioSpec audioSortie;
	SDL_AudioSpec audioBufferSpec;
	Uint8 *audioBuffer;
	Uint32 audioBufferLen;

	void audioCallback(void *udata, Uint8 *stream, int len);

	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		printf("Erreur lors de l'initialisation de SDL.\n");
		exit (EXIT_FAILURE);
	}

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

	int audio_Init(void)
	{
		// Définition des propriétés audio
		audioSortie.freq = 22050;
		audioSortie.format = AUDIO_S16;
		audioSortie.channels = 2;
		audioSortie.samples = 1024;
		audioSortie.callback = audioCallback;
		audioSortie.userdata = NULL;

		// Initialisation de la couche audio

		return 0;
	}

	// A inclure dans votre code pour charger un fichier sonore dans audioBuffer
	if(!SDL_LoadWAV("march_ahead.wav", &audioBufferSpec,
		&audioBuffer, &audioBufferLen))
	{
		printf("Erreur lors du chargement du fichier WAV.\n");
		return 1;
	}
	SDL_FreeWAV(audioBuffer);
	return 0;
}