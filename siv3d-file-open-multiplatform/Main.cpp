# include <Siv3D.hpp>

void Main()
{
	const Font font(30);
	String test = L"test";

	while (System::Update())
	{
		font(test).draw();
	}
}
