#include "Menu.h"

Menu::Menu() : Ente(), window(pGrafico->getWindow())
{
    //std::cout << "Construtora menu iniciada." << std::endl;
    //window = new sf::RenderWindow();
    //winclose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

Menu::~Menu() {
   // delete window;
    //delete winclose;
    delete font;
    delete image;
    delete bg;
}

void Menu::set_values() {
    //window->create(sf::VideoMode(1280, 720), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
    //window->setPosition(sf::Vector2i(0, 0));
    //std::cout << "Setando os valores do menu" << std::endl;
    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("assets/Fonts/PixelFont2.ttf");
    image->loadFromFile("assets/menu.png");

    bg->setTexture(*image);

    //pos_mouse = { 0,0 };
    //mouse_coord = { 0, 0 };

    options = { "Jogo", "Fase1", "Fase2", "Leaderboard", "Quit" };
    texts.resize(5);
    coords = { {590,40},{620,191},{610,282},{590,370},{623,457} };
    sizes = { 20,28,24,24,24 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(4);
    pos = 1;

    //std::cout << "Valores do menu setados." << std::endl;
}
void Menu::loop_events() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 4) {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 1) {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            //Quit
            if (pos == 4) {
                window->close();
            }
            //Iniciar jogo
            else if (pos == 1)
            {
                //simplesmente seta o estado como fase1
                pGrafico->setEstado(ID::fase1);
            }
            //Inicia a fase2
            else if (pos == 2)
            {
                pGrafico->setEstado(ID::fase2);

                
            }
            //Leaderboard
            else if (pos == 3)
            {
                pGrafico->setEstado(ID::leaderboard);

            }

            std::cout << options[pos] << '\n';
        }
    }
}
void Menu::draw_all() {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Menu::run_menu() {
    while (window->isOpen() && pGrafico->getEstado() == ID::menuPrincipal)
    {
        loop_events();
        draw_all();
    }
}
void Menu::Executar()
{
    run_menu();
    //draw_all();
}
