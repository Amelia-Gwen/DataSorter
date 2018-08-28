#include <fstream>
#include <random>
#include <string>
#include <vector>

int main()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> index_distribution(0, 99);
	std::uniform_int_distribution<int> score_distribution(0, 1000);

	std::vector<std::string> names{ "Lavinia", "Ezekiel", "Damian", "Idola", "Marshall",
		"Ezekiel", "Michael", "Gwendolyn", "Aquila", "Kato", "Tucker", "Daryl", "Laurel",
		"Samantha", "Rinah", "Hilel", "Kellie", "Daniel", "Caldwell", "Colton", "Kyra",
		"Zoe", "Ali", "Hermione", "Dana", "Isabella", "Rylee", "Marny", "Odessa", "Jesse",
		"Callie", "Naomi", "Olivia", "Heidi", "Fitzgerald", "Salvador", "Kyra", "Sloane",
		"Basil", "Driscoll", "Aspen", "MacKensie", "Anne", "Skyler", "Jasmine", "Tashya",
		"Wyatt", "Vincent", "Kyra", "Alan", "Fuller", "Cailin", "Dalton", "Tarik", "Price",
		"Merrill", "Jaime", "Quon", "Kitra", "Anastasia", "Nayda", "Amanda", "Philip", "Freya",
		"Kieran", "Kelly", "Wynter", "Amir", "Jacob", "Tarik", "Yardley", "Macy", "Hayfa",
		"Jane", "Zia", "Travis", "Sheila", "Dana", "Prescott", "Drake", "Kameko", "Marsden",
		"Tad", "Tad", "Casey", "Knox", "Teagan", "Hayes", "Knox", "Melanie", "Eagan", "Christopher",
		"Aaron", "Miriam", "Mariko", "Delilah", "Ulric", "Lydia", "Price", "Katelyn" };

	struct student
	{
		std::string name;
		unsigned id;
		unsigned score;

		student(std::string name, unsigned id, unsigned score) : name{ name }, id{ id }, score{ score } {}
	};

	std::vector<student> students;
	int score = 0;
	int index = 0;

	for (std::size_t i = 100000; i < 200000; ++i)
	{
		index = index_distribution(generator);
		score = score_distribution(generator);

		students.emplace_back(student(names[index], i, score));
	}

	std::random_shuffle(students.begin(), students.end());

	std::ofstream writer{ "sampledata.csv" };
    writer << "NAME,ID,SCORE\n";

	for (auto& student : students)
	{
		writer << student.name << ',' << student.id << ',' << student.score << '\n';
	}
}
