#include "Test.hpp"



void Test::runTests()
{
	cout << "Test 1\n";
	test1();
	cout << "Test 2\n";
	test2();
	cout << "Test 3\n";
	test3();
	cout << "Test 4\n";
	test4();
	/*cout << "Test 5\n";
	test5();*/
}
void Test::test1()
{
	Andy andy(850, 200, 20);
	if (andy.getPosition() == sf::Vector2f(850, 200))
		cout << "Success!\n";
}
void Test::test2()
{
	Game game;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Test");
	window.setFramerateLimit(60);
	if (game.helpScreen(window))
		cout << "success!\n";
}
void Test::test3()
{
	Andy andy(850, 200, 20);
	if (andy.getHP() == 20)
		cout << "success!\n";
}
void Test::test4()
{
	Bullet bullet(0, 0, 0, 0, 10);
	if (bullet.getDamage() == 10)
		cout << "success!\n";
}
void Test::test5()
{

}