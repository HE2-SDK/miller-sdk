#pragma once

namespace hh::game {
    void ObjectWorldChunk::RemoveLayer(ObjectWorldChunkLayer* layer) {
        SetLayerEnabled(layer->GetName(), false);
        layers.remove(layers.find(layer));
        layersByName.Erase(layer->GetName());
        layer->Free();
    }
}
