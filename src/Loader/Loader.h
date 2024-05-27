#include <tiny_gltf.h>
#include <string>

class Model {
public:
	virtual bool Load(std::string dataUrl) const=0;
};

class GltfModel :public Model {
public:
	GltfModel() : _model(new tinygltf::Model()) { }
	
	GltfModel(std::string dataUrl) {
		GltfModel();
		Load(dataUrl);
	}

	bool Load(std::string dataUrl) const override {
		std::string err, warn;
		tinygltf::TinyGLTF loader;
		bool ret = loader.LoadASCIIFromFile(_model, &err, &warn, dataUrl.c_str());
		return ret;
	};
private:
	tinygltf::Model* _model;
};

/*
* A factory class to load an object of 3d model
* Usages: ...
*/
class Loader {
public:
	static Loader* Get() {
		if (!instance) {
			Loader();
		}
		return instance;
	}

	template<typename T>
	T* Load(std::string dataUrl) {
		T* p_data = new T();
		if (p_data->Load(dataUrl)) {
			return p_data;
		}

		return nullptr; 
	}

private:
	Loader() {}

	Loader(const Loader& loader) = delete;
	
	~Loader() { delete instance; }

	static Loader* instance;
};