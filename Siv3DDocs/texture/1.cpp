# include <Siv3D.hpp>

void Main()
{
	// đ ăźç””æć­ăăăăŻăčăăŁăäœæ
	const Texture texture{ U"đ"_emoji };

	while (System::Update())
	{
		// ăăŻăčăăŁăćș§æš (400, 0) ăăæç»
		texture.draw(400, 0);

		// ćș§æšăæćźăăȘăć Žć (0, 0) ăăæç»
		texture.draw();

		// ăăŻăčăăŁăă·ăŒăłäž­ćżăăæç»
		texture.draw(Scene::Center());
	}
}
