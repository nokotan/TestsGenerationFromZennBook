# include <Siv3D.hpp>

void Main()
{
	const Texture cat{ U"đ"_emoji };

	const Texture dog{ U"đ"_emoji };

	while (System::Update())
	{
		// 2 ćă«æĄć€§ăăŠæç»
		cat.scaled(2.0).drawAt(200, 300);

		// 1.5 ćă«æĄć€§ăăŠæç»
		cat.scaled(1.5).drawAt(400, 300);

		// ććăźă”ă€ășă«çžźć°ăăŠæç»
		dog.scaled(0.5).drawAt(600, 300);
	}
}
