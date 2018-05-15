import java.awt.List;
import java.util.ArrayList;
import java.util.Map;

public class Song {
    
    public final String title;
    public final int length;

    public Song(String title, int length) {
        this.title = title;
        this.length = length;
    }
    
}

public class Jukebox {

    private int value;
    private final int SONG_VALUE = 15;

    private final Map<String, Song> songs;

    public Jukebox(Map<String, Song> songs) {
        this.songs = songs;
    }

    public void putCoin(int value) {
        this.value += value;
    }

    public boolean canPlaySong() {
        return value >= SONG_VALUE;
    }

    public void play(Song song) {
        if (!canPlaySong() || song == null) {
            throw new Exception();
        }

        value -= SONG_VALUE;
        ...
    }

    public Song choose(String identifier) {
        return songs.getOrDefault(identifier, null);
    }

    public List<Pair<String, String>> songsOnDisplay() {
        return songs.entrySet();
    }
    
}
