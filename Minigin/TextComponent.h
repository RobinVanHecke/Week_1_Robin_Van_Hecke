#pragma once
#include <memory>
#include <string>

#include "ComponentBase.h"

namespace dae
{
	class Font;
	class Texture2D;
}

class TextComponent final : public ComponentBase
{
public:
	TextComponent() = default;

	void SetText(const std::string& text);
	void SetFont(std::shared_ptr<dae::Font> font);

	void Update(dae::GameObject gameObject);


private:
	bool m_NeedsUpdate;
	std::string m_Text;
	std::shared_ptr<dae::Font> m_Font;

};

