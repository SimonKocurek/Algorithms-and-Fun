import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public enum Symbol {
    HEARTS, DIAMONDS, CLUBS, SPADES;
}

public enum Value {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K;
}

public class Card<S extends Symbol, V extends Value> {

    public final S symbol;
    public final V value;

    public Card(S symbol, V value) {
        this.symbol = symbol;
        this.value = value;
    }
}

public class GenericCard extends Card<Symbol, Value> {

    public GenericCard(Symbol symbol, Value value) {
        super(symbol, value);
    }

}

public class Deck<C extends Card> {

    private List<C> cards;

    Deck() {
        this.cards = new ArrayList();
    }

    Deck Standard() {
        Deck deck = new Deck();

        for (Symbol symbol : Symbol.values()) {
            for (Value value : Value.values()) {
                Card card = new GenericCard(symbol, value)
                deck.AddCard(card);
            }
        }

        return deck;
    }

    public void AddCard(C card) {
        cards.add(card);
    }

    public Card deal() {
        Card dealt = cards.get(cards.size() - 1);
        cards.remove(cards.size() - 1);
        return dealt;
    }

    public void RemoveCard(int idx) {
        cards.remove(idx);
    }

    public void Shuffle() {
        Collections.shuffle(cards);
    }

    public int size() {
        return cards.size();
    }

    public bool isEmpty() {
        return cards.isEmpty();
    }
    
}

public class Hand<C extends Card> {

    private List<C> cards;

    Card lookAt(int index ) {
        return cards.get(index);
    }

    Card throwOut(int index) {
        Card dealt = cards.get(index);
        cards.remove(index);
        return dealt;
    }

    public int size() {
        return cards.size();
    }

    public bool isEmpty() {
        return cards.isEmpty();
    }
    
}

public class Table<C extends Card> {

    public final Deck<C> deck;
    
    public final List<Hand<C>> players;

    public Table(Deck<C> deck, int players) {
        this.deck = deck;
        this.players = new ArrayList<>();

        for (int i = 0; i < players; ++i) {
            this.players.add(new Hand());
        }
    }

}
