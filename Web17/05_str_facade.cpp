#include <iostream>
#include <string>
using namespace std;

// Классы подсистемы
class AudioDecoder {
public:
    void decode(const string& file) {
        cout << "Декодирование файла: " << file << endl;
    }
};

class AudioFilter {
public:
    void filter() {
        cout << "Применение фильтра подавления шума" << endl;
    }
};

class AudioPlayer {
public:
    void play() {
        cout << "Проигрываю..." << endl;
    }
};

// Фасад для аудиосистемы
class AudioFacade {
private:
    AudioDecoder decoder;
    AudioFilter filter;
    AudioPlayer player;

public:
    void playAudio(const string& file) {
        decoder.decode(file);
        filter.filter();
        player.play();
    }
};

// Клиентский код
int main() {
    AudioFacade audioFacade;
    audioFacade.playAudio("song.mp3");
}