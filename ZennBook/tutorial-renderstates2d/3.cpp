# include <Siv3D.hpp>

void Main()
{
	const Texture texture{ U"π"_emoji };
	bool bilinear = true;
	double scale = 1.0;

	while (System::Update())
	{
		if (bilinear)
		{
			// γγ€γͺγγ’θ£ιοΌγγγ©γ«γοΌ
			texture.scaled(scale).drawAt(Scene::Center());
		}
		else
		{
			// ζθΏεθ£ι
			const ScopedRenderStates2D sampler{ SamplerState::ClampNearest };
			texture.scaled(scale).drawAt(Scene::Center());
		}

		SimpleGUI::Slider(scale, 0.1, 8.0, Vec2{ 20, 20 }, 200);
		SimpleGUI::CheckBox(bilinear, U"Bilinear", Vec2{ 20, 60 });
	}
}
