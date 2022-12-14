# include <Siv3D.hpp>

struct Building
{
	Texture icon;
	String name, desc;
};

void Main()
{
	Scene::SetBackground(ColorF{ 0.3, 0.6, 0.4 });
	const Font font1{ 30, Typeface::Heavy }, font2{ 15, Typeface::Medium };
	const Array<Texture> emojis = {
		Texture{ U"βοΈ"_emoji }, Texture{ U"β‘"_emoji }, Texture{ U"β₯"_emoji } };
	const Array<Building> buildings =
	{
		{ Texture{ U"π­"_emoji }, U"ε·₯ε ΄", U"ζ―γΏγΌγ³ 6$0 γηη£γγ\nι»ε 3$1 γεΏθ¦" },
		{ Texture{ U"π"_emoji }, U"γΉγΏγΈγ’γ ", U"ζ―γΏγΌγ³ 4$2 γδΎη΅¦γγ\nι»ε 2$1 γεΏθ¦" },
		{ Texture{ U"π"_emoji }, U"γγΌγ", U"ζ―γΏγΌγ³ 2$2 γδΎη΅¦γγ\nη ζ΅γ«γγε»Ίθ¨­γ§γγͺγ" }
	};

	const RoundRect r0{ 0, 0, 360, 100, 6 };
	const RoundRect r1{ 5, 5, 90, 90, 5 };

	while (System::Update())
	{
		for (auto [i, building] : Indexed(buildings))
		{
			const Transformer2D t{ Mat3x2::Translate(40, (40 + i * 110)) };

			r0.drawShadow(Vec2{ 4, 4 }, 8, 1)
				.draw(ColorF{ 0.2, 0.25, 0.3 })
				.drawFrame(1, 1, ColorF{ 0.4, 0.5, 0.6 });
			r1.draw(ColorF{ 0.85, 0.9, 0.95 });
			building.icon.resized(80).drawAt(r1.center());
			font1(building.name).draw(r1.rect.pos.movedBy(100, 0));

			const Vec2 penPos0 = r1.rect.pos.movedBy(100, 42);
			Vec2 penPos = penPos0;
			bool onTag = false;

			for (const auto& glyph : font2.getGlyphs(building.desc))
			{
				if (onTag)
				{
					emojis[(glyph.codePoint - U'0')].resized(25).draw(penPos);
					penPos.x += 25;
					onTag = false;
					continue;
				}

				if (glyph.codePoint == U'$')
				{
					onTag = true;
					continue;
				}

				onTag = false;

				if (glyph.codePoint == U'\n')
				{
					penPos.x = penPos0.x;
					penPos.y += font2.height();
				}
				else
				{
					glyph.texture.draw(penPos + glyph.getOffset());
					penPos.x += glyph.xAdvance;
				}
			}
		}
	}
}
