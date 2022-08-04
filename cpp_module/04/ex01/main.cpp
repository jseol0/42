/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:28:45 by jseol             #+#    #+#             */
/*   Updated: 2022/08/04 12:46:56 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *animals[4];

	Dog *dog = new Dog();
	std::cout << std::endl;

	std::cout << "( Dog 의 0번째 Idea는 'I want a bone' ) " << std::endl;
	dog->getBrain()->putIdea(0, "I want a bone");
	std::cout << std::endl;

	std::cout << "( Dog 의 1번째 Idea는 'I love meats' ) " << std::endl;
	dog->getBrain()->putIdea(1, "I love meats");
	std::cout << std::endl;

	std::cout << "( animals 배열의 0번 인덱스는 Dog. ) " << std::endl;
	animals[0] = dog;
	std::cout << std::endl;

	std::cout << "( animals 배열의 1번 인덱스는, 복사 생성자를 사용한 Dog의 깊은 복사본. ) " << std::endl;
	animals[1] = new Dog(*dog);
	std::cout << std::endl;

	std::cout << "( Dog의 깊은 복사본이므로, 0번째 Idea도 'I want a bone' 으로 기대함. ) " << std::endl;
	std::cout << animals[1]->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "( Dog의 깊은 복사본이므로, 1번째 Idea도 'I love meats' 으로 기대함. ) " << std::endl;
	std::cout << animals[1]->getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	Cat *cat = new Cat();
	std::cout << std::endl;

	std::cout << "( animals 배열의 2번 인덱스는 Dog. ) " << std::endl;
	animals[2] = cat;
	std::cout << std::endl;

	std::cout << "( Cat 의 0번째 Idea는 'I want a tuna' ) " << std::endl;
	cat->getBrain()->putIdea(0, "I want a tuna");
	std::cout << std::endl;

	std::cout << "( Cat 의 1번째 Idea는 'I love fishes' ) " << std::endl;
	cat->getBrain()->putIdea(1, "I love fishes");
	std::cout << std::endl;

	std::cout << "( animals 배열의 3번 인덱스는, 복사 생성자를 사용한 Cat의 깊은 복사본. ) " << std::endl;
	animals[3] = new Cat(*cat);
	std::cout << std::endl;

	std::cout << "( Cat의 깊은 복사본이므로, 0번째 Idea도 'I want a tuna' 으로 기대함. ) " << std::endl;
	std::cout << animals[3]->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "( Cat의 깊은 복사본이므로, 1번째 Idea도 'I love fishes' 으로 기대함. ) " << std::endl;
	std::cout << animals[3]->getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

/*
	std::cout << "----------------------------------------" << std::endl;
	cat->getBrain()->putIdea(0, "CATTTTTT");
	std::cout << animals[2]->getBrain()->getIdea(0) << std::endl;
	std::cout << animals[3]->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
*/

	for (int i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}
