#include <Siv3D.hpp>

void Main()
{
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	const Texture tree{ U"đ˛"_emoji };

	while (System::Update())
	{
		// UV ĺş§ć¨ă 0.0ď˝1.0 ăŽçŻĺ˛ăčśăăă¨ăăăăčżăăăăăłă°
		const ScopedRenderStates2D sampler{ SamplerState::RepeatLinear };

		// ăˇăźăłăŽăľă¤ăşă´ăŁăăăŤăăăăłă°ăăŚćçť
		tree.mapped(Scene::Size()).draw();
	}
}
