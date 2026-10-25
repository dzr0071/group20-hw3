all:
    g++ -std=c++11 main.cpp person.cpp address.cpp product.cpp credit_card.cpp transaction.cpp store.cpp -o store_app

run: all
    ./store_app

clean:
    rm -f store_app
