#pragma once

#ifndef IRENDERABLE_H
#define IRENDERABLE_H

class IRenderable {
	friend class RenderSystem;
protected:
	IRenderable();
	virtual ~IRenderable();
	virtual void Render() = 0;
};

#endif